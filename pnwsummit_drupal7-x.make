; Drush Make file for PNW Drupal Summit
core = 7.x

projects[drupal][type] = core
projects[drupal][download][type] = cvs
projects[drupal][download][root] = :pserver:anonymous:anonymous@cvs.drupal.org:/cvs/drupal
projects[drupal][download][revision] = HEAD
projects[drupal][download][module] = drupal

; projects[] = addthis
projects[] = admin_menu
projects[] = advanced_help
projects[] = backup_migrate
projects[] = contemplate
projects[] = devel
; projects[] = date
projects[] = email
; projects[] = features
projects[] = google_analytics
projects[] = gmap
projects[] = imageapi
projects[] = imce
projects[] = imce_wysiwyg
projects[] = htmlmail
projects[] = jquery_ui
projects[] = jquery_update
; projects[] = logintoboggan
; projects[] = mollom
; projects[] = menu_block
; projects[] = panels
projects[] = print
projects[] = quicktabs
projects[] = rules
projects[] = skinr
projects[] = superfish
projects[] = textsize
projects[] = token
projects[] = views
projects[] = wysiwyg
projects[] = xmlsitemap

projects[tao][type] = theme
projects[tao][download][type] = git
projects[tao][download][url] = git://github.com/developmentseed/tao.git


; Contrib projects



; Patched.
; Explicit versions specified to ensure patches apply cleanly.


; Custom modules


; Features


; Themes
projects[zen][subdir] = "contrib"


; Libraries

libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery-ui-1.7.3.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"
libraries[jquery_ui][destination] = "modules/contrib/jquery_ui"