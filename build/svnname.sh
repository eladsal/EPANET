#!/bin/bash
SVNREV=`svn info | grep Revision | awk -F": " '{print $2}'`
echo $1$2${SVNREV}$3
