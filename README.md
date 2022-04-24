# clog
Simple logging library for C

If you want to save the logs to a file you can use `tee`:
```
someprogram | tee logfile.txt
```

The `-a` command line switch makes tee append to the file
rather than truncating in overwriting it:
```
echo -e "\n---------\nSEPERATOR\n---------\n" >> logfile.txt
someprogram | tee -a logfile.txt
```
