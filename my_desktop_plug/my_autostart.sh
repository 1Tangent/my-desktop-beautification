### BEGIN INIT INFO
# Provides:          svnd.sh
# Required-start:    $local_fs $remote_fs $network $syslog
# Required-Stop:     $local_fs $remote_fs $network $syslog
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: starts the svnd.sh daemon
# Description:       starts svnd.sh using start-stop-daemon
### END INIT INFO



conky -c $HOME/.config/conky/Shelyak-Dark/Shelyak-Dark.conf &> /dev/null &    # 这里为需要执行的命令

