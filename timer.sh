#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage: $0 <seconds>"
  exit 1
fi

seconds=$1

while [ $seconds -gt 0 ]; do
  echo -ne "Time remaining: $seconds\033[0K\r"
  sleep 1
  seconds=$((seconds - 1))
done

echo "Time's up!"


#chmod +x timer.sh
#./timer.sh 60


