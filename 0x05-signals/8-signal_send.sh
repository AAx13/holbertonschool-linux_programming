#!/bin/bash
# This script will send a SIGQUIT function to a process given by the user.

if [ "$#" != "1" ];
then
    echo "Usage: $0 <pid>"
    exit 1
else
    kill -s SIGQUIT $1
fi
