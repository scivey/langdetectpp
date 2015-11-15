import sys
import json

def print_impl(filename):
    with open(filename) as f:
        data = json.load(f)
    freq = data['freq']
    data['name'] = data['name'].replace('-', '_')
    one_grams = []
    bigrams = []
    trigrams = []
    for k, v in freq.iteritems():
        if len(k) == 0:
            continue
        elif len(k) == 1:
            one_grams.append((ord(k[0]), v))
        elif len(k) == 2:
            bigrams.append(
                (tuple(map(ord, k)), v)
            )
        elif len(k) == 3:
            trigrams.append(
                (tuple(map(ord, k)), v)
            )
        else:
            raise ValueError("didn't expect n > 3")
    for collection in (one_grams, bigrams, trigrams):
        collection.sort(key=lambda x: -x[1])

    print '#include "profiles/langs/%s.h"' % data['name']
    print '#include <unordered_map>'
    print '#include <tuple>'
    print ''
    print "static const std::unordered_map<uint32_t, size_t> %s_one_grams {" % data['name']
    for i in xrange(len(one_grams)):
        k, v = one_grams[i]
        item = '  { %i, %i }' % (k, v)
        if i != len(one_grams) - 1:
            item += ','
        print item
    print "};"
    print ''

    print "static const std::unordered_map<std::tuple<uint32_t, uint32_t>, size_t> %s_bigrams {" % data['name']
    for i in xrange(len(bigrams)):
        k, v = bigrams[i]
        item = '  { std::make_tuple<uint32_t, uint32_t>(%i, %i), %i }' % (k[0], k[1], v)
        if i != len(bigrams) - 1:
            item += ','
        print item
    print '};'
    print ''

    print "static const std::unordered_map<std::tuple<uint32_t, uint32_t, uint32_t>, size_t> %s_trigrams {" % data['name']
    for i in xrange(len(trigrams)):
        k, v = trigrams[i]
        item = '  { std::make_tuple<uint32_t, uint32_t, uint32_t>(%i, %i, %i), %i }' % (k[0], k[1], k[2], v)
        if i != len(trigrams) - 1:
            item += ','
        print item
    print '};'
    print ''

    print 'static const std::tuple<size_t, size_t, size_t> %s_n_words {' % data['name']
    print '  %s, %s, %s' % tuple(data['n_words'])
    print '};\n\n'

    print 'namespace langdetectpp { namespace profiles { namespace langs {\n'

    print 'std::unordered_map<uint32_t, size_t> get_%s_one_grams() {' % data['name']
    print '  std::unordered_map<uint32_t, size_t> result = %s;' % ('%s_one_grams' % data['name'])
    print '  return result;'
    print '}\n'

    print 'std::unordered_map<std::tuple<uint32_t, uint32_t>, size_t> get_%s_bigrams() {' % data['name']
    print '  std::unordered_map<std::tuple<uint32_t, uint32_t>, size_t> result = %s;' % ('%s_bigrams' % data['name'])
    print '  return result;'
    print '}\n'

    print 'std::unordered_map<std::tuple<uint32_t, uint32_t, uint32_t>, size_t> get_%s_trigrams() {' % data['name']
    print '  std::unordered_map<std::tuple<uint32_t, uint32_t, uint32_t>, size_t> result = %s;' % ('%s_trigrams' % data['name'])
    print '  return result;'
    print '}\n'

    print 'std::tuple<size_t, size_t, size_t> get_%s_n_words() {' % data['name']
    print '  std::tuple<size_t, size_t, size_t> result = %s_n_words;' % data['name']
    print '  return result;'
    print '}\n'

    print '}}} // langdetectpp::profiles::langs'


def print_header(filename):
    with open(filename) as f:
        data = json.load(f)
    data['name'] = data['name'].replace('-', '_')
    print '#pragma once'
    print '#include <unordered_map>'
    print '#include <tuple>'
    print '#include <folly/Hash.h>'
    print ''
    print 'namespace langdetectpp { namespace profiles { namespace langs {'
    print ''
    print 'std::unordered_map<uint32_t, size_t> get_%s_one_grams();' % data['name']
    print ''
    print 'std::unordered_map<std::tuple<uint32_t, uint32_t>, size_t> get_%s_bigrams();' % data['name']
    print ''
    print 'std::unordered_map<std::tuple<uint32_t, uint32_t, uint32_t>, size_t> get_%s_trigrams();' % data['name']
    print ''
    print 'std::tuple<size_t, size_t, size_t> get_%s_n_words();' % data['name']
    print ''
    print '}}} // langdetectpp::profiles::langs'
    print ''

def throw_usage():
    print 'usage: [script] header|impl $profile_file_path'
    raise ValueError

if __name__ == '__main__':
    if len(sys.argv) < 3:
        throw_usage()
    if sys.argv[1] == 'header':
        print_header(sys.argv[2])
    elif sys.argv[1] == 'impl':
        print_impl(sys.argv[2])
    else:
        throw_usage()

