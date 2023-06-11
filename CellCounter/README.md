## Simple Counting Machine

A friend sent me this video in a discord server [(This One)](https://www.instagram.com/reel/CtLbjdFtTcC/?igshid=MmJiY2I4NDBkZg==), and I thought I might as well try to reproduce it for 1/100th of the cost as a fun little side project.

The machine is very simple, it's just 3 buttons and a 14 segment display, so I thought it might not be that hard to reproduce (boy, was I wrong)

I had also never really programmed a 7-segment display (I've found LCDs much easier), so I thought it would be a good time to use one. 

The 7-segment display I had (common-anode double 7-segment) did not have any documentation anywhere online, so it took a while to manually find the pinout. (Here it is if somone online is attempting to find a pinout for the LONETEK D-353L)

//       CA1 G  F  A  B
//        |  |  |  |  |      -> pins and segments they control
//   ---------    ---------
//   |   A   |    |   A   |
//  F|       |B  F|       |B
//   |---G---|    |---G---|
//  E|       |C  E|       |C
//   |   D   |    |   D   |
//   ---------    ---------
//        |  |  |  |  |      -> pins and segments they control
//        D  DP E  C CA2         

## Project Diagram

![Here][logo1]

[logo1]: https://github.com/EricLindCS/RandomProjects/tree/main/CellCounter/diagram.png "Pinout"