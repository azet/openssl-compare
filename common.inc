#!/usr/bin/env bash
#
# common functions (error handling et cetera)
#

banner="openssl-compare::$(basename ${0}) >>"
function fail() {
        # generic fail function for bash scripts
        # arg: 1 - custom error message
        # arg: 2 - file
        # arg: 3 - line number
        # arg: 4 - exit status
        echo "${banner} ERROR: ${1}."
        [[ ${2+defined} && ${3+defined} && ${4+defined} ]] && \
        echo "${banner} file: ${2}, line number: ${3}, exit code: ${4}. exiting!"
        exit 1
} ; trap 'fail "caught signal"' HUP KILL QUIT

function bold() {
	local text=${1}
	echo "$(tput bold)${text}$(tput sgr0)"
}

