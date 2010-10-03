; Simple example make file

; Drush Make file example
core = 6.x
projects[] = drupal

; Contrib projects
projects[admin_menu][subdir] = "contrib"
projects[backup_migrate][subdir] = "contrib"
projects[calendar][subdir] = "contrib"
projects[ctools][subdir] = "contrib"
projects[date][subdir] = "contrib"
projects[devel][subdir] = "contrib"
projects[email][subdir] = "contrib"
projects[filefield][subdir] = "contrib"
projects[google_analytics][subdir] = "contrib"
projects[image][subdir] = "contrib"
projects[imageapi][subdir] = "contrib"
projects[imagecache][subdir] = "contrib"
projects[imagefield][subdir] = "contrib"
projects[imce][subdir] = "contrib"
projects[imce_wysiwyg][subdir] = "contrib"
projects[jquery_update][subdir] = "contrib"
projects[link][subdir] = "contrib"
projects[mollom][subdir] = "contrib"
projects[pathauto][subdir] = "contrib"
projects[rules][subdir] = "contrib"
projects[site_map][subdir] = "contrib"
projects[token][subdir] = "contrib"
projects[votingapi][subdir] = "contrib"
projects[wysiwyg][subdir] = "contrib"
projects[webform][subdir] = "contrib"
projects[xmlsitemap][subdir] = "contrib"

; Explicit version
projects[cck][subdir] = "contrib"
projects[cck][version] = 2.6

; Patched.
; Explicit versions specified to ensure patches apply cleanly.
projects[views][subdir] = "contrib"
projects[views][type] = "module"
projects[views][version] = "2.11"
; http://drupal.org/node/694094
projects[views][patch][] = "http://drupal.org/files/issues/views-static-cache-resets-694094-7.patch"
; original issue: http://drupal.org/node/357529
projects[views][patch][] = "http://cloud.github.com/downloads/developmentseed/atrium_features/views2_simple_translatables.patch"
; http://drupal.org/node/789674#comment-3230930
projects[views][patch][] = "http://drupal.org/files/issues/789674-5_vocabulary_module.patch"


; Check out the latest version of a project from CVS. Note that when using a
; repository as your project source, you must explictly declare the project
; type so that drush_make knows where to put your project.
projects[data][type] = module
projects[data][download][type] = cvs
projects[data][download][module] = contributions/modules/data
projects[data][download][revision] = DRUPAL-6--1

; Clone a project from github.
projects[tao][type] = theme
projects[tao][download][type] = git
projects[tao][download][url] = git://github.com/developmentseed/tao.git

; Custom modules


; Features


; Themes
projects[zen][subdir] = "contrib"
projects[colourise][subdir] = "contrib"


; Libraries
libraries[tinymce][download][type] = "get"
libraries[tinymce][download][url] = "http://downloads.sourceforge.net/project/tinymce/TinyMCE/3.2.7/tinymce_3_2_7.zip"
libraries[tinymce][directory_name] = "tinymce"
