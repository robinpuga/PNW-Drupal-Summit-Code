<?php
// New site alias on my local
$aliases['newsite'] = array (
  'uri' => 'localhost.newsite.d6',
  'root' => '/Users/robinpuga/Documents/CLIENTS_ALL/2010_PNWDrupalSummit/WEBSITES/newsite',
);


// New site aliases on dev, stage and production servers.

$aliases['new-site.dev'] = array(
  'uri'     => 'dev.newsite.com',
  'root'    => '/home/robinski/domains/dev.newsite.com/public_html',
  'db-url'  => 'mysqli://mysql:mysql_passw0rd@localhost/newsite_mainsite_dev',
  'remote-host' => 'dev.cantrusthosting.coop', 
  'remote-user' => 'robinski',
  'ssh-options' => '-p 33333',
  'path-aliases' => array(
    '%drush' => '/usr/bin',
    '%drush-script' => '/usr/bin/drush',
    '%dump' => '/home/robinski/backups/db/dump.sql',
    '%files' => 'sites/dev.newsite.com/files',
  ),
);

$aliases['new-site.stage'] = array(
  'uri'     => 'stage.newsite.com',
  'root'    => '/home/robinski/domains/stage.newsite.com/public_html',
  'db-url'  => 'mysqli://mysql:mysql_passw0rd@localhost/newsite_mainsite_stage',
  'remote-host' => 'stage.cantrusthosting.coop', 
  'remote-user' => 'robinski',
  'ssh-options' => '-p 33333',
  'path-aliases' => array(
    '%drush' => '/usr/bin',
    '%drush-script' => '/usr/bin/drush',
    '%dump' => '/home/robinski/backups/db/dump.sql',
    '%files' => 'sites/stage.newsite.com/files',
  ),
);

$aliases['new-site.production'] = array(
  'uri'     => 'newsite.com',
  'root'    => '/home/robinski/domains/newsite.com/public_html',
  'db-url'  => 'mysqli://mysql:mysql_passw0rd@localhost/newsite_mainsite_production',
  'remote-host' => 'production.cantrusthosting.coop', 
  'remote-user' => 'robinski',
  'ssh-options' => '-p 33333',
  'path-aliases' => array(
    '%drush' => '/usr/bin',
    '%drush-script' => '/usr/bin/drush',
    '%dump' => '/home/robinski/backups/db/dump.sql',
    '%files' => 'sites/newsite.com/files',
  ),
);

?>
