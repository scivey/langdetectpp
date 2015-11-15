import os

if __name__ == '__main__':
    names = os.listdir('external/langdetect/langdetect/profiles')
    names = map(lambda x: x.replace('-', '_').upper(), names)

    names.append('UNKNOWN')
    names.sort()
    print 'enum class Language {'
    for i in xrange(len(names)):
        name = names[i]
        line = '  %s' % name
        if i < (len(names) - 1):
            line += ','
        print line
    print '};\n'

    print '\n\n'

    print 'std::string stringOfLanguage(Language lang) {'
    print '  switch(lang) {'
    for name in names:
        print '    case Language::%s : return "%s";' % (name, name)
    print '    default : return "NOT_RECOGNIZED";'
    print '  }'
    print '}'
