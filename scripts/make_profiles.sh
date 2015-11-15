#/bin/bash

# PROFILES=`ls external/langdetect/langdetect/profiles`
# echo $PROFILES

for PROFILE in `ls external/langdetect/langdetect/profiles`
do
    SOURCE=./external/langdetect/langdetect/profiles/${PROFILE}
    python ./scripts/transform_profile.py header $SOURCE > ./src/profiles/${PROFILE}.h
    python ./scripts/transform_profile.py impl $SOURCE > ./src/profiles/${PROFILE}.cpp
done
