### Purpose ###
Start a project for the STM32F746G-DISCO board using STM32CubeMX (AKA MX) and
add board support for LCD. Development platform is Linux.

### Requirements ###
* Eclipse Neon (and Java)
* OpenSTM32 Eclipse add ons (http://www.openstm32.org/)
* STM32CubeMX (http://www.st.com/en/development-tools/stm32cubemx.html)

### Procedure ###
Clone project somewhere convenient
  `mkdir stm_workspace && cd $_`
  `git clone git@github.com:HankB/STM32F7explore.git`
Open Eclipse and change to `stm_workspace`.
File > Open Projects from Filesystem and navigate to `.../stm_workspace/STM32F7explore`
Select project and click "Finish"
Enjoy! (or not...)

### Status ###
* Ethernet working
* LCD and logging support seems to be working
* If multiple definitions of various font symbols appears after updating to resolve 
  unresolved LCD_LOG_Init(), LCD_LOG_SetHeader() LCD_LOG_SetFooter() LCD_LineColor(), delete
  files in .../Debug/Utilities/Fonts/

Initial commit - generate code from MX (4.19) after selecting board and making no changes

Clone with `git clone ssh://git@oak:2222/hbarta/STM32F7explore.git` (My private repo only)

### License ###
License to the bulk of this code belongs to the original contributors. To the the best of my knowledge 
all licenses from the various libraries and packages have been preserved and included in this repo.
