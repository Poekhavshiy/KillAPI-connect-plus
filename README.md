# KillAPI Connect Plus

KillAPI Connect Plus is a cross-platform desktop application written in C++ (using MinGW64 on Windows) and Qt6. It is designed to integrate with the Gunhead Discord Bot and optionally display real-time event logs from **Star Citizen** in a customizable window. The application provides a user-friendly interface for configuring settings, monitoring logs, and interacting with the Gunhead API.

---

## Gunhead Discord Bot Integration

KillAPI Connect Plus works alongside the Gunhead Discord Bot, a custom bot for the Gunhead community. The bot processes and displays Star Citizen event logs in Discord.  
**To use the bot:**
- [Install the bot from the Discord App Store](https://discord.com/discovery/applications/1330870778891206707).

## Installation

1. **Download the Application**:
   - [Download the latest version](https://bagman.sparked.network/static/updates/KillApiConnectPlusSetup.msi).

2. **Run the Application**:
   - Double-click `KillAPI.connect.exe` or run from the command line:
     ```sh
     KillAPI.connect.exe [--debug] [--console] [--clear-settings]
     ```

---

## User Interface Overview

### Main Window

Central hub for managing the application:

| **Button**           | **Description**                                                                 |
|----------------------|---------------------------------------------------------------------------------|
| **Start/Stop Monitoring** | Start or stop monitoring the game events file for real-time updates.        |
| **Configure**        | Open the settings window to configure the game folder and API key.              |
| **View Log / Hide Log** | Toggle the visibility of the `LogDisplayWindow`.                             |
| **Status Label**     | Displays the current status (e.g., "Ready", "Invalid Path", "Monitoring...").   |

### Log Display Window

Displays real-time log events with customization options:

| **Button**            | **Description**                                                                 |
|-----------------------|---------------------------------------------------------------------------------|
| **Clear**             | Clears all events from the log display.                                         |
| **Text Color**        | Change the text color.                                                          |
| **Background Color**  | Change the background color.                                                    |
| **+ / - (Font Size)** | Increase or decrease the font size.                                             |

### Settings Window

Configure application preferences:

| **Setting**                  | **Description**                                                                 |
|------------------------------|---------------------------------------------------------------------------------|
| **Check for new versions on startup** | Enable/disable automatic update checks.                                 |
| **Check for updates now**    | Manually check for updates.                                                    |
| **Game Folder**              | Select or enter the Star Citizen game folder path.                             |
| **API Key**                  | Enter and save your Gunhead API key.                                           |
| **Language**                 | Select the UI language.                                                        |
| **Theme**                    | Choose from available UI themes.                                               |

---

## How It Works

1. **Configure the Application**:
   - Open the settings window via "Configure".
   - Select your Star Citizen game folder.
   - Enter your API key (from `/api show_key` in Discord).
   - Choose your preferred theme and language.

2. **Start Monitoring**:
   - Click "Start Monitoring" in the main window.
   - The app will monitor the event log and update the display in real time.

3. **View Logs Locally**:
   - Click "View Log" to open the log display window for real-time event viewing.

4. **Customize Display**:
   - Use the log window controls to adjust appearance to your liking.

---

## Command-Line Options

- `--debug` : Enable debug logging.
- `--console` : Output logs to the console.
- `--clear-settings` : Reset all settings to default values and exit.

---

## Troubleshooting

- **Invalid Path**: Ensure the game log file and `StarCitizen_Launcher.exe` exist in the selected folder.
- **No API Key**: Enter a valid API key in the settings window.
- **Logs**: Check the terminal or log files for detailed error messages.

---

## Screenshots

_Main Window_  
![Main Window](https://github.com/Poekhavshiy/KillAPI-connect/assets/14026302/29606280-0800-4391-9994-45215960b30d)

_Default Star Citizen Folder Location_  
![Default Star Citizen Folder Location](https://github.com/Poekhavshiy/KillAPI-connect/assets/14026302/9263d57b-06c6-4836-b338-2594753f9161)

_API Key Example_  
![API Key](https://github.com/Poekhavshiy/KillAPI-connect/assets/14026302/50897131-3d36-49a7-921d-0065002353a4)

_Log Display Window_  
![Log Display Window](https://github.com/Poekhavshiy/KillAPI-connect/assets/14026302/29606280-0800-4391-9994-45215960b30d)

---

## License

KillAPI Connect Plus is a free tool for the community. Ownership is reserved; not for sale or commercial distribution.
