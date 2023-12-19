/*
 * sorter.h
 *
 * Declares a template function:
 *    
 *   sorter() : k-way merge sort.
 * 
 * 
 * You may add other functions if you wish, but this template function
 * is the only one that need to be exposed for the testing code.
 * 
 * Authors: C. Painter-Wakefield & Tolga Can
 */

#ifndef _SORTER_H
#define _SORTER_H

#include <string>
#include <cstddef>
#include <vector>
#include <queue>

using namespace std;

template <class T>
vector<T> merge(vector<vector<T>> &vecofvec, int k){
	queue<vector<T>> q; 
	for (int i = 0; i<vecofvec.size(); i++){
		q.push(vecofvec[i]);
	}
	vector<T> toMerge1;
	vector<T> toMerge2; 
	vector<T> flippedresults;
	vector<T> results;
	while (q.size() > 1){
		flippedresults.clear();
		results.clear();
		toMerge1 = q.front();
		q.pop();
		toMerge2 = q.front();
		q.pop();
		while ((toMerge1.size()!=0)&&(toMerge2.size()!=0)){
			if (toMerge1.back() >= toMerge2.back()){
				flippedresults.push_back(toMerge1.back());
				toMerge1.pop_back();
			}
			else{
				flippedresults.push_back(toMerge1.back());
				toMerge1.pop_back();
			}
		}
		while (toMerge1.size() > 0){
			flippedresults.push_back(toMerge1.back());
			toMerge1.pop_back();
		}
		while (toMerge2.size() > 0){
			flippedresults.push_back(toMerge2.back());
			toMerge2.pop_back();
		}
		for(int i = flippedresults.size()-1; i>=0; i--){
			results.push_back(flippedresults[i]);
		}
		q.push(results);
	}
	return q.back();
	/*int currvec = 0;
	vector<T> flippedresults;
	vector<T> results;
	T max;
	queue<vector<T>> q;
	vector<vector<T>> vecs;
	for (int i = 0; i<vecofvec.size(); i++){
		q.push(vecofvec[i]);
	}
	while(q.size() <= 1){
		vecs.clear();
		flippedresults.clear();
		results.clear();
		vecs.push_back(q.back());
		q.pop();
		vecs.push_back(q.back());
		q.pop();
		while(vecofvec.size() != 0){
			currvec = 0;
			max = vecofvec[0].back();
			for (int i=0; i<vecofvec.size(); i++){
				if (vecofvec[i].size() == 0){
					vecofvec.erase(vecofvec.begin()+i);
					i--;
				} 
				else if (max<vecofvec[i].back()){
					max=vecofvec[i].back();
					currvec = i;
				}
			}
			flippedresults.push_back(max);
			vecofvec[currvec].pop_back();
			if (vecofvec[currvec].size() == 0){
				vecofvec.erase(vecofvec.begin()+currvec);
			}
			//cout<< "error?";
		}
		for(int i=flippedresults.size()-1; i>=0; i--){
			results.push_back(flippedresults[i]);
		}
		q.push(results);
	}
	return(q.back());*/
	/*int currvec = 0;
	vector<T> flippedresults;
	vector<T> results;
	T max;
	while(vecofvec.size() != 0){
		currvec = 0;
		max = vecofvec[0].back();
		for (int i=0; i<vecofvec.size(); i++){
			if (vecofvec[i].size() == 0){
				vecofvec.erase(vecofvec.begin()+i);
				i--;
			} 
			else if (max<vecofvec[i].back()){
				max=vecofvec[i].back();
				currvec = i;
			}
		}
		flippedresults.push_back(max);
		vecofvec[currvec].pop_back();
		if (vecofvec[currvec].size() == 0){
			vecofvec.erase(vecofvec.begin()+currvec);
		}
		//cout<< "error?";
	}
	for(int i=flippedresults.size()-1; i>=0; i--){
		results.push_back(flippedresults[i]);
	}
	return(results);
	*/
}

template <class T>
void sorter(vector<T> &vec, int k) {  
	// write your solution for k-way merge sort below
	if ( vec.size()==0 || vec.size()==1){
		return;
	}
	else if ( vec.size() < k){
		k=vec.size();
	}
	int sizeofvecs = vec.size()/k;
	int numlargevecs = vec.size()%k;
	vector<vector<T>> vecofvec(k);
	int locationinvec = 0;
	for (int i=0; i<k; i++){
		if (i<numlargevecs){
			vector<T> newvec(vec.begin()+locationinvec,vec.begin()+locationinvec+sizeofvecs+1);
			locationinvec += sizeofvecs+1;
			vecofvec[i] = newvec;
		}
		else{
			vector<T> newvec(vec.begin()+locationinvec,vec.begin()+locationinvec+sizeofvecs);
			locationinvec += sizeofvecs;
			vecofvec[i] = newvec;
		}
		sorter(vecofvec[i],k);
	}
	/*for (int i=0; i<vecofvec.size(); i++){
		cout << "row " << i << "->";
		for (int j=0; j<vecofvec[i].size(); j++){
			cout<<" " << vecofvec[i][j];
		}
		cout<< endl;
	}
	cout<< "suffering" <<endl;*/
	vec=merge(vecofvec,k);
}

#endif
