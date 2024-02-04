# Project #104 DLL

This DLL is used alongside the Vtex client, it should not be removed.

The output file is named "version.dll" in order to use a trick called [import hijacking](https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation/dll-hijacking). Usually version.dll is located in Wow64 (system directory), but the VC++ runtime looks for dynamic libraries in the current directory before going to the PATH.