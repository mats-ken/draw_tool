cd `dirname "$0"`

svn merge vs2015 vs2010     -r $(($1 - 1)):$1
svn merge vs2015 vs2017     -r $(($1 - 1)):$1
svn merge vs2015 vs2017-new -r $(($1 - 1)):$1

