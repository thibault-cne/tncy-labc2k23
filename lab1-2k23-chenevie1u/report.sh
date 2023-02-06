#/bin/bash

REPORT="report.md"

echo "# System Report" > $REPORT

echo "## Linux version"  >> $REPORT
echo '```' >> $REPORT


# uname -a >> $REPORT 2> /dev/null
# lsb_release -a >> $REPORT 2> /dev/null
# sw_vers >> $REPORT 2> /dev/null
# echo -e '```\n' >> $REPORT

echo "## Clang version"  >> $REPORT   
echo '```' >> $REPORT
clang --version >> $REPORT 2> /dev/null
echo -e '```\n' >> $REPORT

echo "## VSCode extensions"  >> $REPORT
echo '```' >> $REPORT
code --list-extensions --show-versions | grep ms-vscode >> $REPORT 2> /dev/null
echo -e '```\n' >> $REPORT

git add report.md &> /dev/null
git commit -m "[report] system report"  &> /dev/null
