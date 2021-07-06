#!/bin/sh
platformio platform update
platformio run -v -e mks_robin_nano_v3
[ -d /Volumes/3DPRINT ] && cp .pio/build/mks_robin_nano_v3/Robin_nano_v3.bin /Volumes/3DPRINT/

