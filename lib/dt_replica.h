#ifndef		DT_REPLICA_H
#define		DT_REPLICA_H


class	dt_replica {
private:

public:
	//int				id;

	int				src_id;
	dt_position		position;
	double			mag_h, mag_v;
	double			rotation;
	dt_area			bb;				// bounding box
};


#endif	//	DT_REPLICA_H
