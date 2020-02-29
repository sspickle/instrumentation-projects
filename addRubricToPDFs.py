"""
Add rubric to pdfs of student notebooks. You need a 'report_rubric.pdf' in the same directory as this file.
"""
import sys
import os
import glob

if len(sys.argv)>1:
    paths=sys.argv[1:]
else:
    paths=[os.curdir]

files = []

for path in paths:
    if os.path.isdir(path):
        files += glob.glob(os.path.join(path,'*.pdf'))
    elif os.path.isfile(path):
        files += [path]

rubricPath = os.path.join(os.path.dirname(sys.argv[0]),'report_rubric.pdf')

print("Files:",files)

for fname in files:
    fpath, fsrc = os.path.split(fname)
    fRoot = os.path.splitext(fsrc)[0]
    fDest = '.'.join([fRoot,'out','pdf'])
    if not os.path.exists(fDest):
        cmd = 'gs -dBATCH -dNOPAUSE -q -sDEVICE=pdfwrite -sOutputFile="%s" "%s" "%s"' % (fDest, rubricPath, fname)
        print("executing:", cmd)
        result = os.system(cmd)
        if not result:
            print("Complete!", fDest)
        else:
            print("Ack Ack!")
    else:
        print("%s already exists" % fDest)
