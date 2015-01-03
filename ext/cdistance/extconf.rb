require 'mkmf'

$CFLAGS = "-shared"

dir_config 'ext/cdistance'
create_makefile 'ext/cdistance'
