#!/bin/bash

# Top Command for CPU Usage => Batch Mode & Single Byte Reading
# We need Screenshot of Particular Timestmap 
# Filter the Line with %Cpu(s)
top -bn1 | grep "%Cpu(s)"