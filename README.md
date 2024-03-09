<h1 align="center">Arduino Nano Music Box</h1>

A simple music box that plays 6 different songs: 
- **Christmas in our Hearts** by Jose Mari Chan
- **Merry Go Round of Life** by Joe Hisaishi
- **I See the Light** by Mandy Moore and Zachary Levi
- **Yellow** by Coldplay
- **Married Life** by Michael Giacchino
- **Almost There** by Anika Noni Rose.

It also has an LED that lights up at every note that is played. You can change the song by unplugging and replugging the Arduino to a power source.

_Used the Arduino IDE to write the code and an Arduino Nano to keep the music box as small as possible. A mini breadboard with 170 tie-points was also used to allow other parts (active buzzer and LED) to be connected._

## PROJECT'S BACKSTORY

This project was created to be a Christmas gift for my best friend who loves music boxes so I figured why not create one myself putting in some of her favorite songs. 

This is my first Arduino project so it does not have the best code and structure.

_I found inspiration for this project from a [YouTube Video](https://www.youtube.com/watch?v=bWzLsHpyGEM&t=12s)._

## CHALLENGES AND RECOMMENDATIONS

Since this was my first Arduino project, there were quite a few challenges I faced such as realizing that since I am using a Nano, it was only limited to a certain code limit; I remedied this by using the Nano's EEPROM. That is where I stored all the notes for each song as well as their duration. I also put the current song number there so that when the Arduino is plugged again it will know which song was played last and which on the song list to play next. 

I hope to implement a button to this project so that you don't have to unplug and replug just to listen to the next song; this was not implemented since materials were constrained.

## INSTALLATION AND RUNNING THE PROJECT

- Download the raw file of [**music_box.ino**](https://github.com/AngelaArmena/arduino-nano-music-box/blob/main/music_box/music_box.ino).
- Run using Arduino IDE.
- If a pop-up shows telling you to create a folder and move the file into it then click **OK**.
- In the IDE, click on the **Select Board** dropdown then **Select Other Board and Port**.
- For the board choose **Arduino Nano** and for port choose **COM5 Serial Port(USB)** _or any other port as long as it has (USB) in it_.
- Connect your Arduino Nano to your PC then click on the **Upload** button.
- The music box should work now.

