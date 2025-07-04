#pragma once

#include <QMainWindow>
#include <QPointer>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QVariant>
#include <QSettings>
#include <QSystemTrayIcon>  // Add this include

// Forward declarations instead of full includes where possible
class QMenu;
class QAction;
class QCloseEvent;
class QTimer;
class SettingsWindow;
class LogDisplayWindow;
class LogMonitor;
class LoadingScreen;

#include "ThemeSelect.h"  // Needed for Theme type
#include "Transmitter.h"  // Needed to instantiate Transmitter

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr, LoadingScreen* loadingScreen = nullptr);
    
    // Add this method declaration
    void retranslateUi();
    
    bool isApplicationShuttingDown() const; // Getter for isShuttingDown

private:
    QPushButton* startButton;
    QPushButton* settingsButton;
    QPushButton* logButton; // Declare logButton
    QLabel* statusLabel;

    QPointer<QWidget> bgContainer; // Background container
    QPointer<SettingsWindow> settingsWindow; // Settings window
    LogDisplayWindow* logDisplayWindow; // Log display window
    LogMonitor* logMonitor; // LogMonitor instance
    QString gameLogFilePath; // Path to the game.log file

    Transmitter transmitter; // Single instance of Transmitter

    QVector<QHBoxLayout*> buttonLayouts; // Store references to each button row layout
    int currentButtonSpacing; // Add this to track spacing independent of QSettings

    bool logDisplayVisible; // Flag to track log display visibility
    bool isMonitoring; // Flag to track monitoring state
    bool isStoppingMonitoring = false; // Flag to track if monitoring is being stopped
    bool isShuttingDown = false; // Add proper member variable

    // Filtering options
    bool showPvP;
    bool showPvE;
    bool showShips;
    bool showOther;
    bool showNPCNames;

    QString lastStatusKey; // Store the untranslated key for status messages

    QTimer* connectionPingTimer;  // Timer for regular connection checks
    
    // System tray
    QSystemTrayIcon* systemTrayIcon;
    QMenu* trayIconMenu;
    QAction* startStopAction;
    QAction* showHideAction;
    QAction* exitAction;

    void closeEvent(QCloseEvent* event) override; // Handle close event
    void focusInEvent(QFocusEvent* event) override; // Handle focus event
    void loadRegexRules();
    void debugPaths(); // Add missing semicolon
    void updateStatusLabel(const QString& status);

    void restartMonitoring();

    void initializeGameMode();
    void createLogDisplayWindowIfNeeded();
    
    QSettings settings{"KillApiConnect", "KillApiConnectPlus"};

public:
    // Getter methods for filter settings
    bool getShowPvP() const { return showPvP; }
    bool getShowPvE() const { return showPvE; }
    bool getShowShips() const { return showShips; }
    bool getShowOther() const { return showOther; }
    bool getShowNPCNames() const { return showNPCNames; }

    // Setter methods for filter settings with signal
    void setShowPvP(bool show);
    void setShowPvE(bool show);
    void setShowShips(bool show);
    void setShowOther(bool show);
    void setShowNPCNames(bool show);
    void startBackgroundInitialization();
    void updateLogDisplayFilterWidth(); // Add this declaration
    
    // System tray methods
    void createSystemTrayIcon();
    void showSystemTrayMessage(const QString& title, const QString& message);
    void toggleMonitoring(); // Add public method to toggle monitoring
    bool getMonitoringState() const; // Add getter for monitoring state
    void activateFromAnotherInstance();

signals:
    void filterSettingsChanged(); 
    void initializationProgress(int value, const QString& message);
    void initializationComplete();

private slots:
    void toggleSettingsWindow();
    void toggleLogDisplayWindow(bool forceNotVisible = false);
    void applyTheme(Theme themeData);
    void handleLogLine(const QString& jsonPayload);
    void startMonitoring();
    void continueStartMonitoring(); // Add helper method for auto-launch flow
    void stopMonitoring();
    void handleMonitoringToggleRequest(); // Add this slot
    void onGameFolderChanged(const QString& newFolder);
    bool verifyApiConnectionAndStartMonitoring(QString apiKey);
    void initializeApp();
    void handleGameModeChange(const QString& gameMode, const QString& subGameMode);
    void sendConnectionPing();
    void emitInitializationComplete();
    
    // System tray slots
    void onSystemTrayActivated(QSystemTrayIcon::ActivationReason reason); // Fixed parameter type
    void onMinimizeToTrayChanged(bool enabled);
    void onSystemTrayStartStopClicked();
    void onSystemTrayShowHideClicked();
    void onSystemTrayExitClicked();

};
