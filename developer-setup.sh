#!/bin/bash
# used only once to allow developers to do
# a signed push to github, ie git commit -S -e
exit 0
git config commit.gpgsign true
