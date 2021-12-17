#
# Regular cron jobs for the seeta-tennis package
#
0 4	* * *	root	[ -x /usr/bin/seeta-tennis_maintenance ] && /usr/bin/seeta-tennis_maintenance
