#include <cstdio>

#include <QApplication>

#include <portaudio.h>
#include <rtmidi/RtMidi.h>

#include "application.hh"

int main(int argc, char *argv[]) {
   PtError pt_err = Pt_Start(1, nullptr, nullptr);
   if (pt_err != ptNoError) {
      fprintf(stderr, "Failed to initialize porttime\n");
      return 1;
   }

   PaError pa_err = Pa_Initialize();
   if (pa_err != paNoError) {
      fprintf(stderr, "Failed to initialize portaudio\n");
      return 1;
   }

   int ret;

   {
      Application app(argc, argv);

      ret = app.exec();
   }

   Pa_Terminate();
   Pt_Stop();
   return ret;
}
