
# Ty Collectible Tracker Plugin

This is a TygerFramework plugin utilizing TygerMemory to read collectible counts from Ty the Tasmanian Tiger and display them as an overlay on the game. This also allows for toggling between level and global counts.

---

## Installing

Manual installation is required for this plugin. Installation involves three files being downloaded and added to your Ty game folder.

### Setting Up TygerFramework

Firstly, if you don't already have plugins set up, download the release version of [TygerFramework](https://github.com/ElusiveFluffy/TygerFramework/releases) (v1.1.0+). You will have a file called 'XInput9_1_0.dll'. 

Place this file in your Ty game folder and launch the game. Once the game is booted up, close it and you should find a Plugins folder has been created. 

### Adding TygerMemory

Next, you'll need to download [TygerMemory](https://github.com/xMcacutt/TygerMemory1/releases) and place this in your dependencies folder. This folder might not exist. Simply add a folder to you 'Plugins' folder called 'Dependencies' and place the downloaded dll into this folder. 

To test if the dll is recognised, launch Ty and check the loaded dependencies listed in the TygerFramework window. If you don't see this window, press F1.

### Adding This Plugin

Finally, head to the releases page for this plugin and download the release version of 'Ty Collectible Tracker Plugin.dll'. Place the downloaded dll into your 'Plugins' folder.

To test if the plugin is recognised, launch Ty and check the loaded plugins listed in the TygerFramework window. If you don't see this window, press F1.

---

## Usage

To use the plugin, press Ctrl+F3 together. This will make the collectible overlay appear. If you want to hide the overlay, simply press the combination again.

Pressing F3 on its own will cause the collectible tracker to toggle between global and level counts for all collectibles where having separate values makes sense.

---

## Special Thanks

Thanks to [Kana (ElusiveFluffy)](https://github.com/ElusiveFluffy) for the architecture of TygerFramework, allowing these plugins to be created.