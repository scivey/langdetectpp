import os

if __name__ == '__main__':
    names = os.listdir('external/langdetect/langdetect/profiles')
    xformed = []
    for item in names:
        current = [0,0,0]
        current[0] = item.title()
        if 'Zh' in current[0]:
            current[0] = current[0].replace('-', '')
        current[1] = item.replace('-', '_')
        current[2] = item.replace('-', '_').upper()
        xformed.append(current)
    xformed.sort(key=lambda x: x[0])


    for _, fn, _ in xformed:
        print '#include "profiles/langs/%s.h"' % fn
    print '\n\n'
    # shared_ptr<Profile> Profile::loadRu() {
    #   shared_ptr<Profile> result(new Profile);
    #   result->lang_ = util::Language::RU;
    #   result->oneGrams_ = langs::get_ru_one_grams();
    #   result->bigrams_ = langs::get_ru_bigrams();
    #   result->trigrams_ = langs::get_ru_trigrams();
    #   result->nWords_ = langs::get_ru_n_words();
    #   return result;
    # }

    for title, fn, lang in xformed:
        print 'shared_ptr<Profile> Profile::load%s() {' % title
        print '  shared_ptr<Profile> result(new Profile);'
        print '  result->lang_ = Language::%s;' % lang
        print '  result->oneGrams_ = langs::get_%s_one_grams();' % fn
        print '  result->bigrams_ = langs::get_%s_bigrams();' % fn
        print '  result->trigrams_ = langs::get_%s_trigrams();' % fn
        print '  result->nWords_ = langs::get_%s_n_words();' % fn
        print '  return result;'
        print '}\n'

    print '\n\n\n'

    for title, _, _ in xformed:
        print 'result->profiles.push_back(Profile::load%s());' % title
