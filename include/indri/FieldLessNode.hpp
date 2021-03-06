/*==========================================================================
 * Copyright (c) 2004 University of Massachusetts.  All Rights Reserved.
 *
 * Use of the Lemur Toolkit for Language Modeling and Information Retrieval
 * is subject to the terms of the software license set forth in the LICENSE
 * file included with this software, and also available at
 * http://www.lemurproject.org/license.html
 *
 *==========================================================================
 */


//
// FieldLessNode
//
// 13 April 2004 -- tds
//

#ifndef INDRI_FIELDLESSNODE_HPP
#define INDRI_FIELDLESSNODE_HPP

#include "indri/ListIteratorNode.hpp"
#include "indri/greedy_vector"
#include "lemur/lemur-platform.h"
#include <string>
namespace indri
{
  namespace infnet
  {
    
    class FieldLessNode : public ListIteratorNode {
    private:
      class FieldIteratorNode* _field;
      indri::utility::greedy_vector<indri::index::Extent> _extents;
      INT64 _constant;
      std::string _name;

    public:
      FieldLessNode( const std::string& name, class FieldIteratorNode* iterator, INT64 constant );

      void prepare( lemur::api::DOCID_T documentID );
      indri::utility::greedy_vector<indri::index::Extent>& extents();
      lemur::api::DOCID_T nextCandidateDocument();
      void indexChanged( indri::index::Index& index );

      const std::string& getName() const;
      void annotate( class Annotator& annotator, lemur::api::DOCID_T documentID, indri::index::Extent &extent );
    };
  }
}

#endif // INDRI_FIELDLESSNODE_HPP

