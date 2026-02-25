#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/**
 * This program calculates the frequency of a MIDI note number
 */

int main(int argc, char *argv[])
{
  // Usage description
  if (argc != 4)
  {
    printf("%s : converts MIDI note to frequency.\n", argv[0]);
    printf("  usage: %s rootA MIDInote octaveDivision\n", argv[0]);
    printf("  range: 0 <= rootA\n");
    printf("  range: 0 <= MIDInote <= 127\n");
    printf("  range: 5 <= octaveDivision\n");

    return 1;
  }

  // a4 is the root A frequency in Hz
  double a4 = strtof(argv[1], NULL);
  if (a4 < 0)
  {
    printf("ERROR: %s frequency isn't a valid root frequency. Enter a value 0 or greater.\n", argv[1]);
    return 1;
  }

  int midinote = strtol(argv[2], NULL, 10);
  if (midinote < 0 || midinote > 127)
  {
    printf("ERROR: %s isn't a valid MIDI note. Make sure your note is in the range 0-127.\n", argv[2]);
    return 1;
  }
  
  // octaveDiv is number of semitones per octave
  int octaveDiv = strtol(argv[3], NULL, 10);
  if (octaveDiv < 5)
  {
    printf("ERROR: %s isn't a valid division of octaves. Make sure your division is above 5.\n", argv[3]);
    return 1;
  }
  // Calculation of frequency for provided MIDI note
  double frequency = a4 * pow(2, (midinote - 69.0) / octaveDiv);

  printf("MIDI note: %d has a frequency of %.2f\n", midinote, frequency);
}
