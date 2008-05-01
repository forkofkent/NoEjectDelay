#!/bin/sh
PATH=/bin:/sbin:/usr/bin:/usr/sbin; export PATH

# ----------------------------------------
# unload
startup="/Library/org.pqrs/SetEjectDelay/scripts/startup.sh"
[ -f "$startup" ] && "$startup" stop

startup="/Library/org.pqrs/NoEjectDelay/scripts/startup.sh"
[ -f "$startup" ] && "$startup" stop

# ----------------------------------------
# uninstall files
rm -rf /Library/org.pqrs/SetEjectDelay
rm -rf /Library/org.pqrs/NoEjectDelay

rm -f /Library/LaunchDaemons/org.pqrs.SetEjectDelay.*
rm -f /Library/LaunchDaemons/org.pqrs.NoEjectDelay.*

exit 0
