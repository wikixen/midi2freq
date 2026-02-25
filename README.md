# midi2freq
Finds the frequency(Hz) of a provided MIDI note.

Usage: ./midi2freq "root A frequency" midinote "octave division"
- Root A frequency is the frequency of the A4 your using for pitch tuning i.e. 440(Standard), 415(Baroque). Enter a number greater than 0.
- Midinote is the midinote whose frequency you want to calculate. Should be 0 <= midinote <= 127.
- Octave division is the amount of semitones per octave. Minimum of 5. 
