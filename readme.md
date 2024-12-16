This is just a proof of concept that I'm compenent and understand Software Engineering principals.

A project derived from me sitting in my car with the aircon on because it was 38c or hotter outside and I was curious to if it was better to keep my door open or closed.

I found the temperature sensor module I had laying around and set up a basic configuration.

![Arduino](/Reference%20images/Arduino_uno.jpg)

After a bit of messing about and getting it to work and give me some output.

![Log](/Reference%20images/temperature_output.png)

With that done, I needed to make sure it was working. Thankfully I had prepared something the previous day when I saw it was going to be uncomfortably hot and used that to see if it was actually working or if I had messed up.

![The best aircon I've ever made](/Reference%20images/temperature_delta.jpg)

With that test showing promising results
![Aircon'd result](/Reference%20images/temperature_output_airconed.png)

I knew at the very least it was reporting something that looked valugely right. I had doing the wrong conversion maths in those screen shots but have fixed it later.

Actual inside temperature was 32.2c and when it was "airconed" it was 20.49c



After that, I was really in the mood and spent a bunch more time working on setting up the LED display, sort of spooked me originally as I had the wrong impression of how the circuit would work. After looking online (which was surprisingly annoying) I found the pin out for the 7 segment led. 


![Displaying a number](/Reference%20images/segment_display.jpg.jpg)


Did some improvements to the readability and other non-critical things as well and will continue to just mess about with the kit, the readme *might* get updated past this point.