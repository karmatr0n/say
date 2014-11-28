// Created by Alejandro Juárez Robles on 11/28/14.
// Copyright (c) 2014 MonsterLabs. All rights reserved.
//
// say.c:
//
// Basic demo to use the CoreAudio framework throught ApplicationServices
// from C
//
//  say 1 Hello!
#include <ApplicationServices/ApplicationServices.h>
#include <CoreFoundation/CoreFoundation.h>
#include <CoreAudio/CoreAudio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  OSErr rc;
  SpeechChannel channel;
  VoiceSpec vs;
  int voice;
  char *text = "What do you want to say?";

  if (!argv[1]) { voice = 1; } else { voice = atoi(argv[1]); }

  if (argc == 3) { text = argv[2]; }
  // GetIndVoice gets the voice define by the (positive) index

  rc = GetIndVoice(voice, // SInt16 index,
                  &vs);   // VoiceSpec *voice

  // NewSpeechChannel basically makes the voice usable
  rc = NewSpeechChannel(&vs, // VoiceSpec *voice,
                        &channel); // Can be NULL

  CFStringRef string = CFStringCreateWithCString(NULL, text, kCFStringEncodingUTF8);
  rc = SpeakCFString(channel, string, NULL);

  if (rc) { fprintf(stderr, "unable to speak!\n");  exit(1); }

  while (SpeechBusy()) sleep(1);

  exit(0);
}

