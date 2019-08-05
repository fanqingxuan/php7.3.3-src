#!/bin/sh
/opt/lampp/bin/phpize
./configure --with-php-config=/opt/lampp/bin/php-config
make && make install
/opt/lampp/bin/php test.php
