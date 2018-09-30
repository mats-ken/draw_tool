The structure of classes is:

dt_file file
	vector<dt_area> bounding_boxes
	vector<dt_layer> layers
		vector<dt_group> groups
			vector<dt_obj> objects
				dt_path path
				dt_text text
				dt_image image
				//dt_replica replica


* "group of group of objects" won't be supported so far.
