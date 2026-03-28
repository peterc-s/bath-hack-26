#!/usr/bin/env bash
#
# basic2tape - tokenize Applesoft BASIC and convert to
# audio for loading on an Apple II via cassette
#
# Usage: basic2tape <input.apl> <output.wav|aif>

prog=''${0##*/}

usage() {
  cat <<-USAGE
Usage: $prog <input.apl> <output.wav|aif>

Tokenizes an Applesoft BASIC text file and converts
it to audio suitable for loading on an Apple II via
cassette.
USAGE
}

if (($# != 2)); then
  usage >&2
  exit 1
fi

input=$1
output=$2

if [[ ! -f $input ]]; then
  echo "$prog: input file '$input' not found" >&2
  exit 1
fi

tmpdir=$(mktemp -d) || exit 1

cleanup() {
  rm -rf "$tmpdir"
}
trap cleanup EXIT

tokenized=$tmpdir/tokenized.bas

echo "tokenizing $input..."
python bastoken/bastoken.py "$input" "$tokenized" || exit 1

wc -c "$tokenized"

echo "generating audio $output..."
c2t-96h -8 -b "$tokenized",801 "$output" || exit 1

echo 'done!'
