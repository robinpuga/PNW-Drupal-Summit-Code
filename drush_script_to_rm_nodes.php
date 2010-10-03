<?php 
// This script removes all the old Community Programming audio nodes that are older than six weeks. 
// Drush note: You must run this command using the "-u admin" inorder to have the permissions to delete nodes

// Get all the Community Programming Nodes and put them into an array
// 1209600 = two weeks in seconds
// 3628800 = six weeks in seconds
$timecheck = time() - 1209600; 
$sql = "SELECT nid, title FROM node WHERE title = 'Community Programming' AND created < " . $timecheck . " ORDER BY created DESC;";

drush_print("SQL query to retrieve community programming recordings:"); 
drush_print($sql); 
$node_count = $nodes_deleted = 0;
$node_items = db_query($sql) ;
if ( $node_items ) {
  while ( $node_item = db_fetch_array($node_items) ) {
    $node_count++;
    // drush_print(print_r($node_item, TRUE));
    if ($node_item['nid']) {
      $node = node_load($node_item['nid']); 
      // print print_r($node, TRUE);
      print $node->audio['file']->filepath . '
';
      // node_delete($node_item['nid']); 
      $nodes_deleted++;
    }    

  }
  drush_print("Found " . $node_count . " nodes and deleted " . $nodes_deleted . " nodes.");
} else {
  drush_print("Not Found: There were no Community Programming nodes found that are older than specified date.");
}

// All finished. 
drush_print("-- POOGED! No going back now. --"); 
?>