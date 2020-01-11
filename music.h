#ifndef MUSIC_H
#define MUSIC_H

#define NOTE_C4  261.63f
#define NOTE_C4s 277.18f
#define NOTE_D4  293.66f
#define NOTE_D4s 311.13f
#define NOTE_E4  329.63f
#define NOTE_F4  349.23f
#define NOTE_F4s 369.99f
#define NOTE_G4  392.00f
#define NOTE_G4s 415.30f
#define NOTE_A4  440.00f
#define NOTE_A4s 466.16f
#define NOTE_B4  493.88f

extern const float SCALE_4[];

enum {
    C,
    Cs,
    D,
    Ds,
    E,
    F,
    Fs,
    G,
    Gs,
    A,
    As,
    B,
    NUM_NOTES
};

typedef struct {
    short* buffer;          //data of sample
    int length;             //length of sample in bytes

    int period;             //#bytes until this sample repeats
    int offset;             //where to start playing the sample next (bytes)

    int attack;             //#bytes to start attacking towards
    int fade;               //#bytes to fade out

    //maybe an array of filters on top of it, where filters are functions
} Sample;

void delete_sample(Sample* sample);

void paint(Sample* brush, unsigned char* canvas, int start, int canvas_length);

#endif 