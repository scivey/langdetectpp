#/bin/bash

# PROFILES=`ls external/langdetect/langdetect/profiles`
# echo $PROFILES

mkdir -p src/profiles/langs

for PROFILE in `ls external/langdetect/langdetect/profiles`
do
    SOURCE=./external/langdetect/langdetect/profiles/${PROFILE}
    python ./scripts/transform_profile.py header $SOURCE > ./src/profiles/langs/${PROFILE}.h
    python ./scripts/transform_profile.py impl $SOURCE > ./src/profiles/langs/${PROFILE}.cpp
done
