#ifndef		DT_REPLICA_H
#define		DT_REPLICA_H


//特定のオブジェクトのレプリカとして本体が編集されたら一緒に変化する
//例えば4面付けのデータで一つをいじったら他も同じように変化する


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
