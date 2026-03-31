Small Project to bring some more fun and longevity into the IW5 Special Ops Gamemode

## Credits
- ### Weapon Ports, Help:
  - Slvr11
  
- ### Testing, Ideas, Help:
  - sevdabeast
  - UwUneedsBunni

- ### Maintainers:
  - urLiver
  
## How to Install
1. Make a backup of your english and main folder from you Game.
2. Download this File ( Uploaded on Mediafire due to Github Max File Size Limit ) [iw_02.iwd](https://www.mediafire.com/file/d6vojn8tsjx24p6/iw_02.iwd/file) and Place it in your main folder.
3. Copy any content of the zone_out subfolders into the english folder.
4. Start the Game.

## How to Compile the GSC
1. Download gsc-tool and place it in gsc folder.
2. Then use gsc-tool -m comp -g iw5 -s pc "filename" to compile the scripts.
3. Take the scripts out of gsc/compiled/iw5 and palce it in the right ff zoneraw folder.

## How to Compile the FastFiles
1. Get OAT ( OpenAssetTool ) and its raw folder and place them in fastfiles.
2. Then get your zone and main folder from your game copy and place them in fastfiles.
3. Get the aizombies_misc.ff and iw4_weapons.ff [from Slvr11 AIZombies Repo](https://github.com/Slvr11/AIZombiesSupreme-PlutoIW5) and place them in your english folder.
4. Modify any of the build.bat scripts so the filepath is correct and run them.

## Checklist
- Weapons
  - Weapons by Name
    - M16
      - [x] 3x Burst -> Full Auto
    - RPG
      - [x] Max Ammo 3 -> 6
    - AA12
      - [x] Clip Size 8 -> 10
      - [x] Max Ammo 32 -> 40
    - M16
      - [x] 3x Burst -> Full Auto
  - Weapons by Type
    - LMGs
      - [ ] Clip Size 100 -> 50
      - [ ] Max Ammo 300 -> 200
  - Weapons Added ( Future will bring more ):
    - IW4
      - RPD
      - PP2000
      - M79
      - Kriss Vector
    - IW5 
      - M1014 
- Streaks
  - [ ] Bring in some more Airstreakes, such as a Support Copter
  - [ ] Implement Two more Support Streaks ( One SWAT Team and a More Fun one named the Boys )
- Ui
  - Main Menu
    - [x] Reworked Main Screen
    - [x] Reworked Gamemode Selection Screen
    - [ ] Update Online Match Gamemode Selection Screens
    - [ ] Update Online Match / Private Match Overall Ui
    - [ ] Add in a Settings and Barracks Button
  - Ingame Hud
    - [ ] Make reset dvar menu load a custom_conf.cfg so people can set custom dvars
    - [x] Custom Radar
    - [x] Remove Weaponname from Weapon Info
    - [x] Bring back Campaign Compass
    - [x] Perk, Self Revive, Armor Display Reworked
    - [ ] Update Claymore and C4 Hud so it doesnt collide with Perk Hud 
  - Shops
    - [x] Reworked Ui
    - [x] Ingame Icons made smallered and dont stick on screen sides
- Overall
  - [x] Increased Level Cap
  - Price Changes of Weapons
    - [x] Pistols 250 -> 450
    - [x] MPistols 1500 -> 1250
    - [x] SMGs 2000 -> 2250
    - [x] ARs 3000 -> 3500
    - [x] LMGs 7000 -> 8500
  - [ ] Update Survival Armories Tabel so anything got a proper level to be unlocked at
  - [ ] Make Self Revive only Buyable 3 Times
  - [ ] Remove Pause from Menu or Turn Prestige Textures into not animated
  - [ ] Add in teaminfo such as money and health 
  - [ ] Move materials and images into specialops_patch
  - [x] Randome chance that the easy enemies become someone else