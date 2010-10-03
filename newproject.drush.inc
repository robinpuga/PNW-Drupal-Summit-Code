<?php
/**
 * @file
 *   Project Init Command based on Moshe's example drush files.
 *
 *   This is a personal drush command that sets up a file structure for a new project.
 *
 *   You can copy this file to any of the following
 *     1. A .drush folder in your HOME folder.
 *     2. Anywhere in a folder tree below an active module on your site.
 *     3. /usr/share/drush/commands (configurable)
 *     4. In an arbitrary folder specified with the --include option.
 *
 */

/**
 * Implementation of hook_drush_command().
 *
 * In this hook, you specify which commands your
 * drush module makes available, what it does and 
 * description.
 *
 * Notice how this structure closely resembles how 
 * you define menu hooks.
 * 
 * @See drush_parse_command() for a list of recognized keys.
 *
 * @return
 *   An associative array describing your command(s).
 */
function newproject_drush_command() {
  $items = array();

  // the key in the $items array is the name of the command.
  $items['new-project'] = array(
    'description' => "Create file structure for starting work on a new Drupal project.",
    'arguments' => array(
      'client_name' => 'The abbreviated name of the client for this project.',
    ),
    'options' => array(
      'url' => 'Eventual production website URL.',
    ),
    'examples' => array(
      'drush new-project NewClient --url=example.com',
    ),
    'aliases' => array('np'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap at all.
  );

  $items['db create'] = array(
    // the name of the function implementing your command.
    'callback' => 'create_empty_db',
    // a short description of your command
    'description' => "This feature creates a new utf-8 database.",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap at all.
  );

  return $items;
}

/**
 * Implementation of hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'
 *
 * @param
 *   A string with the help section (prepend with 'drush:')
 *
 * @return
 *   A string with the help text for your command.
 */
function newproject_drush_help($section) {
  switch ($section) {
    case 'drush:new-project':
      return dt("Setup project file structure for new client.");
    case 'drush:db create':
      return dt("Create an empty utf-8 database.");
  }
}

/**
 * Example drush command callback.
 *
 * This is where the action takes place.
 *
 * In this function, all of Drupals API is (usually) available, including
 * any functions you have added in your own modules/themes.
 *
 * To print something to the terminal window, use drush_print().
 *
 */
function drush_newproject_new_project($clientname = 'NewClient') {

  drush_print("Creating file structure for new client: " . $clientname . "");
  
  // Get the current working directory
  $this_dir = getcwd();
  
  // Create directory for new project. Name: YYYY_ClientName
  $new_project_name_str = date("Y") . "_" . $clientname;
  $new_project_dir = $this_dir . "/" . $new_project_name_str;
  if ( !mkdir($new_project_dir, 0755) ) {
    drush_print("Failed to make new project directory: " . $new_project_dir . "\n");
    drush_print("Exiting. \n");    
    return;
  } else {
    drush_print("\nNew Project Structure:");    
    drush_print("\n  " . $new_project_name_str . "");    
  }
  
  //
  // Create internal folders and files that I like to use. 
  //
  
  // Couldn't get this to create the new file. Keeps saying that the file doesn't exist 
  // and it won't create the file for some reason. 
  // $dev_notes_file_name = $new_project_dir . "/dev_notes.txt";
  // $initial_file_contents = "Project created: " . date("F j, Y, g:i a");
  // if ( ($file_ptr = fopen($new_project_dir . $dev_notes_file_name, "a")) ) {
  //   fwrite($file_ptr, $initial_file_contents);
  //   fclose($file_ptr);
  //   drush_print("   " . $dev_notes_file_name .  "\n");
  // }
  
  $docs_dir = $new_project_dir . "/" . "DOCS";
  if ( mkdir($docs_dir, 0755) ) {
    drush_print("   /DOCS");
    if ( mkdir($docs_dir . "/FROM_CLIENT", 0755) ) {
      drush_print("     /FROM_CLIENT");
    }
    if ( mkdir($docs_dir . "/FROM_ME", 0755) ) {
      drush_print("     /FROM_ME");
    }
    if ( mkdir($docs_dir . "/FROM_DESIGNER", 0755) ) {
      drush_print("     /FROM_DESIGNER");
    }
  }
  
  $web_dir = $new_project_dir . "/" . "WEBSITES";
  if ( mkdir($web_dir, 0755) ) {
    drush_print("   /WEBSITES");
    if ($url = drush_get_option('url')) {
      if ( mkdir($web_dir . "/dev." . $url, 0755) ) {
        drush_print("     /dev." . $url);
      }
      if ( mkdir($web_dir . "/stage." . $url, 0755) ) {
        drush_print("     /stage." . $url);
      }
      if ( mkdir($web_dir . "/production." . $url, 0755) ) {
        drush_print("     /production." . $url);
      }
    }
  }
  
  drush_print("\nDone and done. Start making the Awesome.");

  return;
}


/**
 * Example drush command callback.
 *
 * This is where the action takes place.
 *
 * In this function, all of Drupals API is (usually) available, including
 * any functions you have added in your own modules/themes.
 *
 * To print something to the terminal window, use drush_print().
 *
 */
function create_empty_db($db_name) {
  
  $query = "CREATE DATABASE `" . $db_name . "` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;";
  
  // Robin's specific MySQL setup
  $cred = ' -h localhost -u root --password=mysql_s3cr3t_passw0rd ';
  $cred = escapeshellcmd($cred);
  
  // Save $query to a tmp file. We will redirect it in.
  if ($file = drush_save_data_to_temp_file($query)) {

    $exec = 'mysql ';
    $exec .= $cred;
    $exec .= " < $file";
    $return = drush_op('system', $exec) !== FALSE;
    drush_op('unlink', $file);

    return $return;
  }
}