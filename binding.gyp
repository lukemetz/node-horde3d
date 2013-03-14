{
  'variables': {
    'platform': '<(OS)',
  },

  'targets' : [
    {
      'target_name': 'horde3d',
      'defines': [
        'VERSION=0.0.1'
      ],
      'sources': ['src/Horde3D.cpp'],
      'include_dirs': [
        '/usr/local/include/horde3d/',
      ],

      'library_dirs': [
        './horde3d/lib'
      ],

      'conditions' : [
        ['OS=="linux"', {'libraries': ['-lHorde3D']}]
      ]
    },
    {
      'target_name': 'horde3dutil',
      'defines': [
        'VERSION=0.0.1'
      ],
      'sources': ['src/Horde3DUtil.cpp'],
      'include_dirs': [
        '/usr/local/include/horde3d/',
      ],

      'library_dirs': [
        './horde3d/lib'
      ],

      'conditions' : [
        ['OS=="linux"', {'libraries': ['-lHorde3D', '-lHorde3DUtils']}]
      ]
    }
  ]
}
