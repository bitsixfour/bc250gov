## WHAT IS THIS??
This is meant to work with the system management microcontroller instead of traditonal "governors" that just write to amdgpu. This is a very aggressive idle-reducer which reduces about to 40W from my smart plug, and is meant to make it used as a "server" for fun rather than squeezing the full power of the sillicon for compute. 

This writes to the SMU various codes such as 0xB8 directly. Note that this is still a WIP, because of the fact that I have not have had the time to mess around sending it various base-10 messages. It works fine for my device but use at your own risk.


