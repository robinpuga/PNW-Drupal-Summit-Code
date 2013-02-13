<?php 
// Originally written in a fit of mad panic for Vancouver Co-op Radio.
// This script removes all the old Community Programming audio nodes that are older than six weeks. 
// Drush note: You must run this command using the "-u admin" inorder to have the permissions to delete nodes

// This script has been updated for the PNWDrupal Summit presentation

// Get all the Community Programming Nodes and put them into an array
// 1209600 = two weeks in seconds
// 3628800 = six weeks in seconds
$timecheck = time() - 30; // currently set to 30 secs
// $sql = "SELECT nid, title FROM node WHERE title = 'Community Programming' AND created < " . $timecheck . " ORDER BY created DESC;";
$sql = "SELECT nid, title, vid, created, updated FROM node WHERE created < " . $timecheck . " ORDER BY created DESC;";


drush_print("SQL query to retrieve nodes:"); 
drush_print($sql . "\n"); 
$node_count = $nodes_deleted = 0;
$node_items = db_query($sql) ;
if ( $node_items ) {
  while ( $node_item = db_fetch_array($node_items) ) {
    $node_count++;
    // drush_print(print_r($node_item, TRUE));
    if ($node_item['nid']) {
      // If you needed to do some special processing on the node then grab the node object.
      // $node = node_load($node_item['nid']); 
      drush_print("Deleting node: " . $node_item['title']);
      node_delete($node_item['nid']); 
      $nodes_deleted++;
    }    

  }
  drush_print("\nFound " . $node_count . " nodes and deleted " . $nodes_deleted . " nodes.\n");
} else {
  drush_print("Not Found: There were no Community Programming nodes found that are older than specified date.");
}

// All finished. 
drush_print("-- POOGED! No going back now. --"); 
?>