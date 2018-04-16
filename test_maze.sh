#! /bin/bash
# Simple test for the maze_test program.
run () {
echo "$*"
if $*
then echo 'success'
else echo 'error'
fi
}
run ./test_maze <<EOF
maze.txt
EOF
echo '-----------------------------------'

exit 0
