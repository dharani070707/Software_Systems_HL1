#here we will create a program to execute softlink , hardlink and myfifo file

if ln -s /tempDir/file1.txt slink.txt; then
    echo "Symlink created successfully"
else
    echo "Failed to create symlink"
fi

if ln file2.txt hlink.txt; then
    echo "Hard link created: hlink.txt → file2.txt"
else
    echo "Failed to create hard link"
fi

if mkfifo myfifo.txt; then
    echo "FIFO created: myfifo"
else
    echo "Failed to create FIFO"
fi

echo
echo "Directory listing (ls -l):"
ls -l
rm slink.txt hlink.txt myfifo.txt 
