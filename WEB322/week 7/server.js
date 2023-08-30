const Sequelize = require('sequelize');
const env = require('dotenv');
env.config();

var sequelize = new Sequelize(
  process.env.PG_USERDB, // I should put this information in cyclic because it doesn't exist in github.
  process.env.PG_USERDB,
  process.env.PG_PASSWORD,
  {
    host: process.env.PG_HOST,
    dialect: 'postgres',
    port: 5432,
    dialectOptions: {
      ssl: { rejectUnauthorized: false },
    },
    query: { raw: true },
  }
);

////Authentication
// sequelize
//   .authenticate()
//   .then(() => {
//     console.log('success!');
//   })
//   .catch((err) => {
//     console.log('error! ERR OBJ:' + err);
//   });

// var User = sequelize.define('User', {
//   name: Sequelize.STRING,
//   title: Sequelize.STRING,
// });

//we want to specify our own auto-incrementing primary key and remove the createdAt and updatedAt fields.
var Project = sequelize.define(
  'Project',
  {
    project_id: {
      type: Sequelize.INTEGER,
      primaryKey: true, // use "project_id" as a primary key
      autoIncrement: true, // automatically increment the value
    },
    title: Sequelize.STRING,
    description: Sequelize.TEXT,
  },
  {
    createdAt: false, // disable createdAt
    updatedAt: false, // disable updatedAt
  }
);

//This is not perfect code to use User table.
//Only for showing the connection between User and Project.
//See the example in the note
//User.hasMany(Project);

// //This is for assignment 5
// sequelize.sync().then(() => {
//   application.listen(PORT, httpCallback);
// });

sequelize
  .sync()
  .then(() => {
    // console.log('success??');
    // Project.create({
    //   title: 'New Project 2',
    //   description: 'New Project 2 = desctibe here',
    // })
    //   .then((project) => {
    //     console.log(project);
    //   })
    //   .catch((err) => {
    //     console.log(err);
    //   });

    //Project.findAll()
    Project.findOne({
      //findAll returns an array, findOne returns an object
      where: {
        project_id: 1,
      },
    })
      .then((data) => {
        console.log(data);
      })
      .catch((err) => {
        console.log(err);
      });
  })
  .catch((err) => {
    console.log(err);
  });

//     Project.update(
//       {
//         description: 'new description',
//       },
//       {
//         where: {
//           project_id: 1,
//         },
//       }
//     )
//       .then((data) => {
//         console.log(data);
//       })
//       .catch((err) => {
//         console.log(err);
//       });
//   })
//   .catch((err) => {
//     console.log(err);
//   });

//   Project.destroy({
//     where: {
//       project_id: 2,
//     },
//   })
//     .then((data) => {
//       console.log(data);
//     })
//     .catch((err) => {
//       console.log(err);
//     });
// })
// .catch((err) => {
//   console.log(err);
// });
