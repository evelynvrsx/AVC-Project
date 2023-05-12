# AVC Team 5

# Deadlines
- AVC project plan 2.5% 12 may
- Progress report 2.5% 23 may
- Robot testing 10% 31 may
- Project report 15% 3 June


# links to slides
https://ecs.wgtn.ac.nz/foswiki/pub/Courses/ENGR101_2023T1/LectureSchedule/ENGR101_Lecture14.pdf
https://ecs.wgtn.ac.nz/foswiki/pub/Courses/ENGR101_2023T1/LectureSchedule/ENGR101_Lecture15.pdf


# List of team members and their contact numbers
Evelyn Salim: salimevel@myvuw.ac.nz
Riana Pho: phoriana@myvuw.ac.nz
Ju Ran: juran@myvuw.ac.nz
James Small: smalljame@myvuw.ac.nz

# Roles 
- 3 software people: Riana, Evelyn, Ran
  - Architect: James
  - Tester: Riana
  - Coordinator: Evelyn
- 1 hardware person: Ran


# General design of the software. How it is divided into pieces
- Open the gate by exchange with the server over WiFi
    - The general design of the software will have a function that can open the gate and we can connect to the server by requesting a          connection, 

- To follow the wiggly line, we detect the black pixels by getting the (000) and (111)
    - Take an array of the white pixels (which contains mostly 0s) and multiply each element of it with indexes - middle array
    - (maybe) Turn the frame into greyscale 
    - Check whether pixel is black or not: If the rgb is below a certain threshold. the pixel is black 
    - Code to get white pixel: get_pixel(row,col,3)
        - Could put this in a for loop and if its white, return 1, if its black, return 0
    - Use ratio so that its adaptable with lighting
    - Trialling an array of horizontal pixels at a set height of an image 
    - (maybe) Adding all the elements in an array together using the 'inner_product' to get which path to go to 
       0 is middle, when you go to negative, its left, and positive to right, and adjust the robot to 0 for it to stay in the middle 
    - Make the robot follow the middle line. 
    - When it gets to 1 way intersections, turn to the side with more black pixels 
      Example: 111111000000 (since black pixels is the right, go to right side)
    - When it gets to 2 way intersections, always go to the left
    - For the 3rd 2 way intersection, it will detect 111111111 (which is all white). 
      If it detects this, turn 180 degrees (so its facing other way)
      It will detect a 2 way intersection again so it will turn right
     
- When it gets to the 3rd quadrant to 4th quadrant, detect the red pixels and move the camera up.
    - Turn right, scan for the amount of red pixels and see whether it exceeds a certain amount. 
    - If it does, that means the first red pole is there, approach the red pole, make it stop at a certain distance. 
    - Scan to the left until it detects a green pole (use the same algorithm as when it detects the red pole), approach & stop 
    - Scan to the right until it detects a blue pole (same algorithm), approach & stop

    - Scan to the left to detect a red ball. (same algorithm). If it does, approach it and push it off the table. 
      Don't make it stop at a certain distance. (maybe could use 'redcount == 2' or something?)

# Road map
| Start date | Task description                  | Responsible team member     | End date | Outcome                |
| ------     | ------                            | ------                      | ------   |  ------                | 
| 08/05      | AVC project plan                   | Evelyn, Riana               | 12/05    | Completed project plan |
| 08/05      | Connect gate to server and open by exchange with the server over WiFi | Evelyn, James               | 12/05    | Completed connection   |
| 08/05      | Construct hardware                | Ran, James                  | 19/05    | In progress  |
| 12/05      | Quadrant 2 code - To follow the line, we detect the black pixels by getting the (000) and (111), store in an array, Error is 0 if line is in the middle of the screen. Positive if line is to the left of the centre, negative otherwise.    | Evelyn, James, Ran, Riana   | 17/05    | In progress  |
| 17/05      | Quadrant 3 code                   | Evelyn, James, Ran, Riana   | 24/05    |  .  |
| 24/05      | Quadrant 4 code                   | Evelyn, James, Ran, Riana   | 30/05    |  .  |
| 12/05      | Progress report                   | Evelyn, Riana               | 23/05    |  .  |
| 31/05      | Final testing                     |                             | 31/05    |  .  |







## Getting started

To make it easy for you to get started with GitLab, here's a list of recommended next steps.

Already a pro? Just edit this README.md and make it your own. Want to make it easy? [Use the template at the bottom](#editing-this-readme)!

## Add your files

- [ ] [Create](https://docs.gitlab.com/ee/user/project/repository/web_editor.html#create-a-file) or [upload](https://docs.gitlab.com/ee/user/project/repository/web_editor.html#upload-a-file) files
- [ ] [Add files using the command line](https://docs.gitlab.com/ee/gitlab-basics/add-file.html#add-a-file-using-the-command-line) or push an existing Git repository with the following command:

```
cd existing_repo
git remote add origin https://gitlab.ecs.vuw.ac.nz/course-work/engr101/2023/project3/t5/avc-team-5.git
git branch -M main
git push -uf origin main
```

## Integrate with your tools

- [ ] [Set up project integrations](https://gitlab.ecs.vuw.ac.nz/course-work/engr101/2023/project3/t5/avc-team-5/-/settings/integrations)

## Collaborate with your team

- [ ] [Invite team members and collaborators](https://docs.gitlab.com/ee/user/project/members/)
- [ ] [Create a new merge request](https://docs.gitlab.com/ee/user/project/merge_requests/creating_merge_requests.html)
- [ ] [Automatically close issues from merge requests](https://docs.gitlab.com/ee/user/project/issues/managing_issues.html#closing-issues-automatically)
- [ ] [Enable merge request approvals](https://docs.gitlab.com/ee/user/project/merge_requests/approvals/)
- [ ] [Automatically merge when pipeline succeeds](https://docs.gitlab.com/ee/user/project/merge_requests/merge_when_pipeline_succeeds.html)

## Test and Deploy

Use the built-in continuous integration in GitLab.

- [ ] [Get started with GitLab CI/CD](https://docs.gitlab.com/ee/ci/quick_start/index.html)
- [ ] [Analyze your code for known vulnerabilities with Static Application Security Testing(SAST)](https://docs.gitlab.com/ee/user/application_security/sast/)
- [ ] [Deploy to Kubernetes, Amazon EC2, or Amazon ECS using Auto Deploy](https://docs.gitlab.com/ee/topics/autodevops/requirements.html)
- [ ] [Use pull-based deployments for improved Kubernetes management](https://docs.gitlab.com/ee/user/clusters/agent/)
- [ ] [Set up protected environments](https://docs.gitlab.com/ee/ci/environments/protected_environments.html)

***

# Editing this README

When you're ready to make this README your own, just edit this file and use the handy template below (or feel free to structure it however you want - this is just a starting point!). Thank you to [makeareadme.com](https://www.makeareadme.com/) for this template.

## Suggestions for a good README
Every project is different, so consider which of these sections apply to yours. The sections used in the template are suggestions for most open source projects. Also keep in mind that while a README can be too long and detailed, too long is better than too short. If you think your README is too long, consider utilizing another form of documentation rather than cutting out information.

## Name
Choose a self-explaining name for your project.

## Description
Let people know what your project can do specifically. Provide context and add a link to any reference visitors might be unfamiliar with. A list of Features or a Background subsection can also be added here. If there are alternatives to your project, this is a good place to list differentiating factors.

## Badges
On some READMEs, you may see small images that convey metadata, such as whether or not all the tests are passing for the project. You can use Shields to add some to your README. Many services also have instructions for adding a badge.

## Visuals
Depending on what you are making, it can be a good idea to include screenshots or even a video (you'll frequently see GIFs rather than actual videos). Tools like ttygif can help, but check out Asciinema for a more sophisticated method.

## Installation
Within a particular ecosystem, there may be a common way of installing things, such as using Yarn, NuGet, or Homebrew. However, consider the possibility that whoever is reading your README is a novice and would like more guidance. Listing specific steps helps remove ambiguity and gets people to using your project as quickly as possible. If it only runs in a specific context like a particular programming language version or operating system or has dependencies that have to be installed manually, also add a Requirements subsection.

## Usage
Use examples liberally, and show the expected output if you can. It's helpful to have inline the smallest example of usage that you can demonstrate, while providing links to more sophisticated examples if they are too long to reasonably include in the README.

## Support
Tell people where they can go to for help. It can be any combination of an issue tracker, a chat room, an email address, etc.

## Roadmap
If you have ideas for releases in the future, it is a good idea to list them in the README.

## Contributing
State if you are open to contributions and what your requirements are for accepting them.

For people who want to make changes to your project, it's helpful to have some documentation on how to get started. Perhaps there is a script that they should run or some environment variables that they need to set. Make these steps explicit. These instructions could also be useful to your future self.

You can also document commands to lint the code or run tests. These steps help to ensure high code quality and reduce the likelihood that the changes inadvertently break something. Having instructions for running tests is especially helpful if it requires external setup, such as starting a Selenium server for testing in a browser.

## Authors and acknowledgment
Show your appreciation to those who have contributed to the project.

## License
For open source projects, say how it is licensed.

## Project status
If you have run out of energy or time for your project, put a note at the top of the README saying that development has slowed down or stopped completely. Someone may choose to fork your project or volunteer to step in as a maintainer or owner, allowing your project to keep going. You can also make an explicit request for maintainers.
