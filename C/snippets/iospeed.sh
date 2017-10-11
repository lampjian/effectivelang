if [ -f "sun.txt" ]
then
	echo "sun.txt exists."
	rm -f sun.txt
fi

dd if=/dev/zero of=sun.txt bs=5M count=10

