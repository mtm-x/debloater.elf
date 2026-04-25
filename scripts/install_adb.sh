#!/bin/bash

#easy to write a script in shell lol
url = "https://dl.google.com/android/repository/platform-tools_r33.0.0-linux.zip"
curl -L "$url" -o "$(pwd)/platform-tools-r33.0.0.zip"
unzip "$(pwd)/platform-tools-r33.0.0.zip"
rm "$(pwd)/platform-tools-r33.0.0.zip"

