# Arduino-Fencing-Scoring-Machine
A very simplified fencing Scoring machine based on Arduino UNO R3, only programmed for Epee fencers.
# Description and background
Fencing score machine for epee is an open circuit set up by the system, which is closed when a valid attack is made. In other word, the fencing score machine is connected to the electric epee by a body cord, and the loop closed when an attack is made and the button on the top of the blade is pressed. For reader without knowledge about fencing rules, here is a reference of how fencing equipments work:https://entertainment.howstuffworks.com/fencing-equipment.htm
The machine in this system would light, beeps and show scores, and timer to assist human referee to ref the game.
Here is a image of real-day fencing scoring machine:
![image](https://github.com/XiangyiTan/Arduino-Fencing-Scoring-Machine/assets/152521923/1b4c3304-5c18-4389-b08c-5f8de0cdffae)


There are two push-buttons that simulate the tips of the blades of two fencers, and a valid attack is made when the push-button is pressed. Another pushbutton on the breadboard is the timer switch. Pressing this button once will display the one-minute timer, pressing it again will turn the timer off and display the scoreboard. The real time score and the timer are displayed on an LCD screen, the contrast of which is controlled by a potentiometer. When fencers use this system to fence, as soon as a button is pressed to simulate an attack, the LED of that side would light up, the buzzer would beep, and the scoreboard would add one point to that side. If a side is the first to score 5 points and win, the buzzer and LED would flash to remind the human referee. This Arduino system is a real fencing scoreboard that could be used in an épée game by connecting the blade with banana plugs to the digital pins of two push buttons on the board. In the future, components such as ESP32 and Bluetooth could be added to create a wireless version of the fencing score machine.

Similar programs: https://forum.arduino.cc/t/fencing-scoring-machine/149087 and https://github.com/wnew/fencing_scoring_box. These two programs display the signal of valid attacks but lack a scoreboard and a timer. Some parts of coding in https://github.com/wnew/fencing_scoring_box are very valuable that there are codes for the two blades sabre and foil.
# Components lists and specifications
  1. Arduino Uno R3
  2. 3 Push buttons (Two for signal of blades, one for switch the display of timer and scoreboard)
  3. LCD screen(Scoreboard and timer; two 7 seg displays are also fine, but have to build on a microcontroller with more pins such as Arduino mega, or the 7-segment display needs to connect to a shift register)
  4. LEDs for displaying signals of valid attacks (Recommended red and green, since those two are widely applied in real-world fencing boxes, an LED matrix could be used if needed)
  5. Buzzer for informing fencers that there is a valid attack made. (Repeat the function of LEDs, but it's necessary since fencers are not allowed to look at the light during the game, they have to hear the beep to stop.)
  6. A potentiometer to adjust the LCD screen
  
  Further components with more complex functions that could be added to the machine:
  
  6. Yellow and White LEDs
     Yellow LED shows the yellow and red cards that a fencer obtained in one match, and white LED turns on when the blade is disconnected. 

  7. To connect this machine to a real-life fencing game, the two push buttons could be replaced with banana plugs that could connect the blades and body cords of fencers.
    
  8. Wireless components could be added, and a dashboard display rather than an LCD or 7-seg display could be achieved with ESP32. Reference here:https://calibur.ai (ps:really expensive)
  # Circuit diagram
  Generate in TinkerCAD
  ![image](https://github.com/XiangyiTan/Arduino-Fencing-Scoring-Machine/assets/152521923/6aba27f2-2c98-4266-864b-dacfacbbf18c)
  # Demostration
  Demostration vedio avaliabe.
