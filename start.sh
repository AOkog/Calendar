#!/bin/bash
# start.sh - runs the Qt app inside the container

# Ensure DISPLAY is set (fallback to :0 if not)
DISPLAY=${DISPLAY:-:0}

export DISPLAY

./build/calendar-app
